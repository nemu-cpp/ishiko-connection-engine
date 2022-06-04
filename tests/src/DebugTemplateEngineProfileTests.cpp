/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "DebugTemplateEngineProfileTests.hpp"
#include "Nemu/WebFramework/DebugTemplateEngineProfile.hpp"
#include "Nemu/WebFramework/MapViewContext.hpp"
#include <Ishiko/Errors.hpp>
#include <Ishiko/FileSystem.hpp>

using namespace Ishiko;
using namespace Nemu;

DebugTemplateEngineProfileTests::DebugTemplateEngineProfileTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "DebugTemplateEngineProfile tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("render test 1", RenderTest1);
    append<HeapAllocationErrorsTest>("render test 2", RenderTest2);
}

void DebugTemplateEngineProfileTests::ConstructorTest1(Test& test)
{
    DebugTemplateEngineProfile templateEngineProfile;

    ISHIKO_TEST_PASS();
}

void DebugTemplateEngineProfileTests::RenderTest1(Test& test)
{
    DebugTemplateEngineProfile templateEngineProfile;

    MapViewContext context;
    std::string renderedView =
        templateEngineProfile.render("DebugTemplateEngineProfileTests_RenderTest1.html", context, nullptr);

    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("DebugTemplateEngineProfileTests_RenderTest1.html");
    Error error; // TODO: use exception
    BinaryFile outputFile = BinaryFile::Create(outputPath, error);
    outputFile.write(renderedView.c_str(), renderedView.size());
    outputFile.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("DebugTemplateEngineProfileTests_RenderTest1.html",
        "DebugTemplateEngineProfileTests_RenderTest1.html");
    ISHIKO_TEST_PASS();
}

void DebugTemplateEngineProfileTests::RenderTest2(Test& test)
{
    DebugTemplateEngineProfile templateEngineProfile;

    MapViewContext context;
    context.map()["var1"] = "value1";
    std::string renderedView =
        templateEngineProfile.render("DebugTemplateEngineProfileTests_RenderTest2.html", context, nullptr);

    boost::filesystem::path outputPath =
        test.context().getTestOutputPath("DebugTemplateEngineProfileTests_RenderTest2.html");
    Error error; // TODO: use exception
    BinaryFile outputFile = BinaryFile::Create(outputPath, error);
    outputFile.write(renderedView.c_str(), renderedView.size());
    outputFile.close();

    ISHIKO_TEST_FAIL_IF_FILES_NEQ("DebugTemplateEngineProfileTests_RenderTest2.html",
        "DebugTemplateEngineProfileTests_RenderTest2.html");
    ISHIKO_TEST_PASS();
}
