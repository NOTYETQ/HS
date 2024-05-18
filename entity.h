#ifndef ENTITY_H
#define ENTITY_H

#include "errors.h"

#include <QString>
#include <QVariant>
#include <memory>
#include <unordered_map>

class Entity{
public:
  // Default constructor
  Entity();
  ~Entity();

  // Function to add a setter function to the setterMap_
  void addSetter(const std::string& column_name, const std::function<void(const QVariant&)>& setter);
  // Map to store column names and corresponding setter functions
  std::unordered_map<std::string, std::function<void(const QVariant&)>> setterMap_;
};

#endif // ENTITY_H
