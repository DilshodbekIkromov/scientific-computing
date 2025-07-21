//=====================================================================
// crtp_logger_example.cpp
//
// Demonstrates the Curiously Recurring Template Pattern (CRTP) to implement
// static-polymorphic loggers without virtual functions.
// Two concrete loggers are provided: TextLogger and JsonLogger.
//=====================================================================

#include <iostream>
#include <string>

/*
 * 1. CRTP Base Class Template: Logger<Derived>
 *    - Defines the public interface `log()`.
 *    - Delegates formatting to `Derived::format()` via a compile-time cast.
 */
template<typename Derived>
class Logger {
public:
    // Public method exposed to users.
    // It takes a message and produces formatted output.
    void log(const std::string& msg) {
        // Perform a downcast to Derived* so we can call the format() implemented there.
        // static_cast is safe because `this` truly points to a Derived instance.
        std::string formatted = static_cast<Derived*>(this)->format(msg);

        // Output the formatted message to stdout.
        std::cout << formatted << std::endl;
    }
};

/*
 * 2. TextLogger:
 *    - Inherits from Logger<TextLogger>!
 *    - Implements `format()` to prepend a simple human-readable tag.
 */
class TextLogger : public Logger<TextLogger> {
public:
    // Called by Logger<TextLogger>::log().
    // Returns the message prefixed with a [TEXT] label.
    std::string format(const std::string& msg) {
        return "[TEXT] " + msg;
    }
};

/*
 * 3. JsonLogger:
 *    - Inherits from Logger<JsonLogger>!
 *    - Implements `format()` to wrap the message in a JSON object.
 */
class JsonLogger : public Logger<JsonLogger> {
public:
    // Called by Logger<JsonLogger>::log().
    // Constructs a valid JSON string with one "log" field.
    std::string format(const std::string& msg) {
        return std::string("{\"log\": \"") + msg + "\"}";
    }
};

/*
 * 4. main(): Demonstration of both loggers.
 *    - Create instances of TextLogger and JsonLogger.
 *    - Call log(), which dispatches to the correct format() at compile time.
 */
int main() {
    TextLogger textLogger;
    JsonLogger jsonLogger;

    // When log() is called:
    //   - Logger<TextLogger>::log() is invoked for textLogger.
    //   - static_cast<Derived*> points to the TextLogger instance.
    //   - TextLogger::format() is called, then printed.
    textLogger.log("Application started");   // Output: [TEXT] Application started

    // Similarly, Logger<JsonLogger>::log() calls JsonLogger::format(), then prints.
    jsonLogger.log("An error occurred");    // Output: {"log": "An error occurred"}

    return 0;
}
