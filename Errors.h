#ifndef ERRORS_H
#define ERRORS_H
#include <exception>
#include <string>

class DatabaseException : public std::exception {
public:
    DatabaseException(const std::string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

class ValidationException : public std::exception {
public:
    ValidationException(const std::string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

class QueryException : public std::exception {
public:
    QueryException(const std::string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};
#endif // ERRORS_H
