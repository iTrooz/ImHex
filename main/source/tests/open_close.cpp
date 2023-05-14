#include "tests/open_close.hpp"

namespace hex::test::open_close {
    void registerTests(ImGuiTestEngine* engine){
        ImGuiTest* test = IM_REGISTER_TEST(engine, "demo_test", "test1");
        test->TestFunc = [](ImGuiTestContext* ctx)
        {
            ctx->ItemClick("**/test.txt");
        };
    }
}