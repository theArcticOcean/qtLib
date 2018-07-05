The folder has some cases that show how to define ourself qml type and import in special page.
We can put all custom qml types files in one folder, the import methods have two ways:
<li> Just write import statement in qml file header part: import "FolderName"
<li> Register all qml types using C++ function qmlRegisterType(), then import relevant module in special page.
