CTE: C++ Template Engine
========================

Basic template engine first version has a file such as:

    #include <list>
    #include <string>

    %%

    homepage(std::list<std::string> names)

    %%
    <!DOCTYPE html>
    <html>
      <head>
        <title>Users</title>
      </head>
      <body>
        <ol>
        <% for (auto &&item : names) { %>
          <li><< item >></li>
        <% } %>
        </ol>
      </body>
    </html>

It would generate a header *homepage.h* file such as:

    #ifndef HOMEPAGE_RANDOMGIBBERISH
    #define HOMEPAGE_RANDOMGIBBERISH

    #include <list>
    #include <string>
    #include <sstream>

    auto homepage(std::list<std::string> names) -> std::string;

    #endif

A compilation unit *homepage.cpp* also generated such as:

    #include "homepage.h"

    auto homepage(std::list<std::string> names) -> std::string {
      std::stringsteam output;

      output << R"(<!DOCTYPE html>
    <html>
      <head>
        <title>Users</title>
      </head>
      <body>
        <ol>)";

      for (auto &&item : names) {
        output << R"(<li>)"> << item << R"(</li>)";
      }

      output << R"(</ol>
      </body>
    </html>)";

    return output.str();
    }

