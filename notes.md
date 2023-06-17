### Thoughts along the journey

###### Destructor Utilization
* All the detroy/cleanup events can be handled in the destructor of some object. Thus it will automatically clean itself up when it goes out of scope.
* In this way, make our main clean as well.

##### Dependency Injection
1. Constructor Injection
   * You cannot create the class without the other classes.
   * Be careful to deal with NULL. (Guard Pattern)
   * You should use it when your class has a dependency that the class requires in order to work properly.
   * Additionally, you should use it when the dependency has a lifetime longer than a single method.

2. Property Injection
   * Also known as setter injection.
   * Use it when a dependency is optional or when a dependency can be changed after the class is instantiated. 
   * Setting up the possibility of temporal coupling.

3. Method Injection
   * It can be used when the dependency could change with every use.
   * Or when the implementation of a depencency will vary.


##### RAII
* Resource Aquisition Is Initialization
* Encapsulation:
  - The constructor acquires the resource and establishes all class incariants / throw exceptions if that cannot be done.
  - The destructor releases the resource and never throws exceptions
* Always use the resource via an instance of a RAII-class that either:
  - has automatic storage duration or temp lifetime itself
  - or has lifetime that is bound by the lifetime of an automatic/temp object

##### Static
* Mark constants static.
* Since they are taking unnecessary space in the class. If you mark them as statics, then the compiler will optimize them to compile-time constants ans they will take no extra space in the objects.

##### Const
* When you take read-only params by pointer of reference, be sure to mark them as const. 
* This will prevent you from accidentally modifying stuff that should not be.