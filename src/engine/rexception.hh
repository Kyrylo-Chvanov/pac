#pragma once

#include <exception>

/**
 * @brief Throw this if RManager::LoadBackground fails
 * 
 */
class ResourceLoadingException : public std::exception {
 public:
  ResourceLoadingException(const char *message) : message_{message} {}
  const char *what() const noexcept override { return message_; }

 private:
  const char *message_;
};
