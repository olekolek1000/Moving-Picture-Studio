#pragma once
#include "texturemanager.hpp"
#include "configmanager.hpp"
#include <string>
#include <map>

struct optVar{
	std::string varstr;
	float varfloat;
};

class sceneEditor;

class ThemeManager{
private:
    std::string themeName;
    std::string defaultThemeName = "default";
    TextureManager texMan;
	std::map<std::string, optVar> vars;
    sceneEditor * scene;
	void loadVariables();
public:
    void init(sceneEditor * scene);
	ConfigManager config;
    void addTexture(std::string name, std::string location, int texspace = RGB, int texfiltering = LINEAR);
    void loadTheme(std::string name);
	void reloadThemes();
    std::string getLocation(std::string location);
    std::string getLocationDefault(std::string location);
    std::string getThemeName();
    void removeTexture(const char * n);
    Texture & operator [](const char* n);
};
