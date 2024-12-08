#include "../lib/mongoose/mongoose.h"
#include <iostream>

// static void put_callback(struct mg_connection *c, int ev, void *ev_data) {
//     if (ev == MG_EV_HTTP_MSG) { // Check if we received an HTTP message
//         struct mg_http_message *hm = (struct mg_http_message *)ev_data;
        
//         // Print out the response body
//         std::cout << "Response body: " << std::string(hm->body.buf, hm->body.len) << std::endl;

//         // You can determine the status code based on your application's logic
//         // For example, if you expect a 200 OK response:
//         if (hm->proto.len > 0) { // Check if there is a valid HTTP protocol
//             std::cout << "Received HTTP message with protocol: " << std::string(hm->proto.buf, hm->proto.len) << std::endl;
//         }
//     }
// }

// int update() {
//     struct mg_mgr mgr; // Event manager
//     mg_mgr_init(&mgr); // Initialize event manager

//     // Define the URL and data for the PUT request
//     const char *url = "http://localhost:8080/endpoint";
//     const char *put_data = "{\"key\":\"value\"}";

//     // Start the HTTP PUT request

//     struct mg_connection *c = mg_connect(&mgr, url, put_callback);
//     if (c == nullptr) {
//         std::cerr << "Connection failed." << std::endl;
//         return 1;
//     }

//     // Run the event loop
//     for (;;) {
//         mg_mgr_poll(&mgr, 1000); // Poll for events every second
//     }

//     mg_mgr_free(&mgr); // Clean up
//     return 0;
// }