/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/web-framework/blob/main/LICENSE.txt
*/

#include "TestWebRequest.hpp"

using namespace std;

TestWebRequest::TestWebRequest(string uri)
    : m_uri(move(uri))
{
}
