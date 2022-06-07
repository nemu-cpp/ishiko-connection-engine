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
#include <boost/variant.hpp>
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
        virtual boost::optional<std::string> getLayout(const WebRequest& request, Ishiko::Error& error);
        virtual std::string getView(const WebRequest& request, Ishiko::Error& error) = 0;
        
        // TODO: ultimately this is what I want I think but until I make ViewContext an interface this would involve
        // too much copying
        //virtual ViewContext getContext(const WebRequest& request, Ishiko::Error& error) const = 0;
    };

    class DeclarativeCallbacks : public Callbacks
    {
    public:
        class PrefixMapping
        {
        public:
            PrefixMapping(std::string inputPrefix, std::string outputPrefix);

            std::string getOutput(const std::string& input) const;

        private:
            // If the input starts with m_inputPrefix then the m_inputPrefix prefix will be removed and replaced by the
            // value of m_outputPrefix. If m_inputPrefix is empty then the value of m_outputPrefix will always be
            // preprended to the output. Both m_inputPrefix and m_outputPrefix can be empty.
            std::string m_inputPrefix;
            std::string m_outputPrefix;
        };

        typedef boost::variant<std::string, PrefixMapping> Mechanism;

        DeclarativeCallbacks(const char* profile, const char* layout, const char* urlPathPrefix, 
            const char* contentPrefix);
        DeclarativeCallbacks(boost::optional<std::string> profile, boost::optional<std::string> layout,
            std::string urlPathPrefix, std::string contentPrefix);

        boost::optional<std::string> getProfile(const WebRequest& request, Ishiko::Error& error) override;
        boost::optional<std::string> getLayout(const WebRequest& request, Ishiko::Error& error) override;
        std::string getView(const WebRequest& request, Ishiko::Error& error) override;

    private:
        boost::optional<std::string> m_profile;
        boost::optional<std::string> m_layout;
        PrefixMapping m_view;
    };

    ViewWebRequestHandler(Callbacks& callbacks);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) override;

    const MapViewContext& context() const noexcept;
    MapViewContext& context() noexcept;

private:
    Callbacks& m_callbacks;
    MapViewContext m_context;
};

}

#endif
