#include "tests/tests.hpp"
#include "tests/open_close.hpp"

using namespace hex::test;

namespace hex::test {
    ImGuiTestEngine* setupTestEngine(){
        ImGuiTestEngine* engine = ImGuiTestEngine_CreateContext();
        ImGuiTestEngineIO& test_io = ImGuiTestEngine_GetIO(engine);
        test_io.ConfigVerboseLevel = ImGuiTestVerboseLevel_Info;
        test_io.ConfigVerboseLevelOnError = ImGuiTestVerboseLevel_Debug;
        test_io.ConfigRunSpeed = ImGuiTestRunSpeed_Cinematic; // Default to slowest mode in this demo

        ImGuiTestEngine_Start(engine, ImGui::GetCurrentContext());
        ImGuiTestEngine_InstallDefaultCrashHandler();
        
        return engine;
    }

    void registerAllTests(ImGuiTestEngine* engine){
        open_close::registerTests(engine);
    }
    
    void queueAllTests(ImGuiTestEngine* engine){
        ImGuiTestEngine_QueueTests(engine, ImGuiTestGroup_Unknown, "all");
    }

    void runAllTests(){
        ImGuiTestEngine* engine = setupTestEngine();
        registerAllTests(engine);
        queueAllTests(engine);

        // EventManager::subscribe<EventFrameBegin>([this] {

        // });
    }
}