HEADERS     = GUI.h 
SOURCES	    = GUI.cpp MainGUI.cpp
FORMS       = GUI.ui

# install
target.path = mainGUI
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = .
INSTALLS += target sources

