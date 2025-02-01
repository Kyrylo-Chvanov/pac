#pragma once

#include "raylib.h"
#include <exception>

class GameException : public std::exception {
 public:
  GameException(const char *message) : message_{message} { TraceLog(LOG_FATAL, message); }
  virtual ~GameException() {}
  const char *what() const noexcept override { return message_; }
 private:
  const char *message_;
};

/**
 * @brief Throw this if RManager::LoadBackground fails
 * 
 */
class TextureLoadingException : public GameException {
 public:
  TextureLoadingException(const char *message) : GameException(message) {}
};
