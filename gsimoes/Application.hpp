#include "window.cpp"
#include "Playground.cpp"


class Application{
    public:
    Application();
    ~Application();
    void Draw();
    private:
    MainSDLWindow* win;
    Playground* pg;
};