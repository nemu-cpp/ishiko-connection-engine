/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_WEBFRAMEWORK_REQUESTHANDLERS_VIEWWEBREQUESTHANDLER_HPP_

#include "../MapViewContext.hpp"
#include "../WebRequestHandler.hpp"
#include <boost/optional.hpp>
#include <Ishiko/Errors.hpp>
#include <string>

namespace Nemu
{
    
// TODO: in the end this has become quite complex with the callbacks to implement and in the end we are only calling
// responsebuilder.view and holding a view context. If developer is coding this he might as well make his own class
// it will be easier than implementing the callbacks, but derivation from the class might be a good option. And where
// this class will be needed is when it is used in a declarative configuration (which seems to be the
// seems to be a suitable role for the DeclarativeCallbacks class).
class ViewWebRequestHandler : public WebRequestHandler
{
public:
    class Callbacks
    {
    public:
        virtual ~Callbacks() = default;

        virtual boost::optional<std::string> getProfile(const WebRequest& request, Ishiko::Error& error);

        virtual std::string getView(const WebRequest& request, Ishiko::Error& error) = 0;
        // TODO: ultimately this is what I want I think but until I make ViewContext an interface this would involve
        // too much copying
        //virtual ViewContext getContext(const WebRequest& request, Ishiko::Error& error) const = 0;
    };

    // TODO: this is in fact a mixin.
    // TODO: should be called something with "View" in it beacuse it only implements getView
    // TODO: the most basic case would be to remove the leading '/' to make it a relative path. Should I make this the
    // default constructor?
    class PrefixMappingCallbacks : public Callbacks
    {
    public:
        PrefixMappingCallbacks(std::string urlPathPrefix, std::string contentPrefix);

        std::string getView(const WebRequest& request, Ishiko::Error& error) override;

    private:
        // If the URL path starts with hm_urlPathPrefix then the m_urlPathPrefix prefix will be removed and replaced by
        //  the value of m_contentPrefix. If m_urlPathPrefix is empty then the value of m_contentPrefix will always be
        // preprended to the URL path. Both m_urlPathPrefix and m_contentPrefix can be empty.
        std::string m_urlPathPrefix;
        std::string m_contentPrefix;
    };

    class DeclarativeCallbacks : public PrefixMappingCallbacks
    {
    public:
        DeclarativeCallbacks(boost::optional<std::string> profile, std::string urlPathPrefix,
            std::string contentPrefix);

        boost::optional<std::string> getProfile(const WebRequest& request, Ishiko::Error& error) override;

    private:
        boost::optional<std::string> m_profile;
    };

    ViewWebRequestHandler(Callbacks& callbacks);
    ViewWebRequestHandler(Callbacks& callbacks, std::string layout);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

    const MapViewContext& context() const noexcept;
    MapViewContext& context() noexcept;

private:
    Callbacks& m_callbacks;
    boost::optional<std::string> m_layout;
    MapViewContext m_context;
};

}

#endif
