///
/// @file    World.h
/// @author  Craig Warner 
///

#ifndef PROJECT_TEMPLATE_A_HELLO_WORLD_H
#define PROJECT_TEMPLATE_A_HELLO_WORLD_H

/// @brief    Here you put a short description of the namespace
/// Extended documentation for this namespace
/// @author  Craig Warner
namespace ProjectTemplate {
namespace ProjA {

/// @brief   Here you put a short description of the class
/// Extended documentation for this class.
/// @author 	Craig Warner
class World {
public:

  /// @brief   Greets the caller
  /// @author 	Craig Warner
  /// @brief	Simple hello world
  void greet();

  /// @brief   Returns the value passed to it
  /// Longer description that is useless here.
  /// @author 	Craig Warner
  /// @param n (In) input number.
  /// @return Returns the input number given.
  int returnsN(int n);
};

} // namespace Hello
} // namespace ProjectTemplate

#endif // PROJECT_TEMPLATE_A_HELLO_WORLD_H
