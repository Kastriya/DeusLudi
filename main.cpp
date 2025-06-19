#include <exception>
#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>
#include <stdexcept>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class TrianglesLEARN {
public:
  void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
  }

private:
  // Variables
  GLFWwindow *window;
  VkInstance instance;

  // Methods
  void initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // creatre the window
    window = glfwCreateWindow(WIDTH, HEIGHT, "Leanr Vulkan", nullptr, nullptr);
  }

  void initVulkan() { createInstance(); }

  void mainLoop() {
    while (!glfwWindowShouldClose(window)) {
      // Event loop (down)
      glfwPollEvents();
    }
  }

  void createInstance() {
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "VulkanLEARN GAME ENGINE";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Create Info
    /*  tells
        the Vulkan driver which global extensions and validation layers we want
       to use. Global here means that they apply to the entire program and not a
       specific device.
    */

    VkInstanceCreateInfo
        createInfo{}; // MANDATORY STRUCT FOR CREATING INSTANCE!!
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char **glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;
    createInfo.enabledLayerCount = 0;

    // Finally creating the Instance
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    // checking if the result is correct
    if (result != VK_SUCCESS) {
      throw std::runtime_error("failed to create instance!");
    } else if(result == VK_SUCCESS){
      std::cout << "successfully created instance!" << std::endl;
    }
  }

  // Deallocate the memory, and explicitely destroy Vulkan Objects
  void cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
  }
};

int main(int argc, char *argv[]) {
  TrianglesLEARN app;

  try {
    app.run();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
