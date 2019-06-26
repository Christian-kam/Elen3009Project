# Elen3009Project

This  game is a remake of the classic arcade game Defender. A layered object-
oriented approach has been used to design the game implemented in ANSI/ISO C++ in conjunction with the SFML 2.3.1 graphics library. 

The application layers have been separated using a combination of the Model-View-Controller and the Model-View-Presenter design patterns. The
’model’ layer contains the game entities and is modelled using inheritance. The ’view’ renders all of the game objects. The ’controller’ encapsulates
all of the core game logic and links the ’model’ and the ’presenter’ layers. The ’presenter’ creates a link between the ’controller’ and the ’view’ layers.
Basic game functionality has been achieved with a scoring system, player lives, smart bombs, power-ups and a mini-map with screen-scrolling as
extra major and minor features. 

Testability of the solution is increased by the use of separation of concerns. Design flaws in the model exist and lead
to inappropriate class functionality, as can be seen in the Logic class. Possible functionality improvements could include the addition of Bombers,
Humanoids and game levels. The design promotes the maintainability of the framework due to the high level of abstraction throughout the code.
