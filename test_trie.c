
#include <stdio.h>
#include <stdlib.h>

void setUp(void) {
    // Code to run before each test, if needed
}

void tearDown(void) {
    // Code to run after each test, if needed
}

void test_load_dictionary(void) {
    FILE *file = fopen("dictionary/dictionary_short.txt", "r+");
    TEST_ASSERT_NOT_NULL_MESSAGE(file, "Failed to open dictionary file");
    if (file != NULL) {
        fclose(file);
    }
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_load_dictionary);
    UNITY_END();
    return 0;
}
