// Copyright (c) 2017, Baidu.com, Inc. All Rights Reserved

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#ifndef BDG_PALO_BE_SRC_COMMON_UTIL_HTTP_HANDLER_H
#define BDG_PALO_BE_SRC_COMMON_UTIL_HTTP_HANDLER_H

namespace palo {

class HttpRequest;
class HttpChannel;

// Handler for on http request
class HttpHandler {
public:
    virtual ~HttpHandler() { }
    virtual void handle(HttpRequest *req) = 0;

    virtual bool request_will_be_read_progressively() { return false; }

    // This funciton will called when all headers are recept.
    // return 0 if process successfully. otherwise return -1;
    // If return -1, on_header function should send_reply to HTTP client
    // and function wont send any reply any more.
    virtual int on_header(HttpRequest* req) { return 0; }

    virtual void on_chunk_data(HttpRequest* req) { }
    virtual void free_handler_ctx(void* handler_ctx) { }
};

}

#endif
