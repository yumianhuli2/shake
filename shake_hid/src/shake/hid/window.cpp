#include "window.hpp"

#include <GLFW/glfw3.h>

#include "shake/core/log.hpp"
#include "shake/core/contracts/contracts.hpp"

//#include "shake/graphics/gl_debug_message.hpp"

namespace shake {
namespace { // anonymous
//----------------------------------------------------------------
// A callback which allows GLFW to report errors whenever they occur
static void glfwErrorCallback(int error, const char *description)
{
    fprintf(stderr, "GLFW returned an error:\n\t%s (%i)\n", description, error);
    CHECK_FAIL( "A glfw error occurred." );
}

} // namespace anonymous

//----------------------------------------------------------------
Window::Window
(
    const uint16_t      width,
    const uint16_t      height,
    const std::string&  title,
    const bool          is_resizable,
    const size_t        window_samples
)
{
    // Initialise GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Could not start GLFW\n");
        exit(EXIT_FAILURE);
    }

    // Enable the GLFW runtime error callback function defined previously.
    glfwSetErrorCallback(glfwErrorCallback);

    // Set core window options (adjust version numbers if needed)
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 6 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    // Set additional window options
    glfwWindowHint( GLFW_RESIZABLE, is_resizable );
    glfwWindowHint( GLFW_SAMPLES, window_samples );  // MSAA
    glfwWindowHint( GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE );

    // Create window using GLFW
    m_window = glfwCreateWindow
    (
        width, height,
        title.c_str(),
        nullptr, nullptr
    );

    // Ensure the window is set up correctly
    if (!m_window)
    {
        glfwTerminate();
        CHECK_FAIL( "Could not open GLFW window" );
    }

    // Let the window be the current OpenGL context and initialise glad
    glfwMakeContextCurrent(m_window);

    // Disable vsync
    glfwSwapInterval( 0	); 

    LOG( std::string { "GLFW version " } + glfwGetVersionString() );
}

LoaderFunctionAddress Window::get_glfw_gl_load_proc() const 
{
    return ( LoaderFunctionAddress ) glfwGetProcAddress;
}

//----------------------------------------------------------------
Window::~Window()
{
    // Terminate GLFW (no need to call glfwDestroyWindow)
    glfwTerminate();
}

//----------------------------------------------------------------
bool Window::get_should_close() const   { return glfwWindowShouldClose(m_window);       }
void Window::set_should_close()         { glfwSetWindowShouldClose(m_window, GL_TRUE);  }

//----------------------------------------------------------------
GLFWwindow* Window::get_glfw_window_ptr() const { return m_window; }

//----------------------------------------------------------------
void Window::poll_events()
{
    glfwPollEvents();
}

//----------------------------------------------------------------
void Window::swap_buffers() { glfwSwapBuffers(m_window); }

} // namespace shake

