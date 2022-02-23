#include <check.h>
#include <stdlib.h>

#include "../src/floatconv.h"

START_TEST(test_bytes_to_double)
{
    uint8_t i[8] = {
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x48,
        0x7A,
        0x40,
    };

    ck_assert_double_eq(bytesToDouble(i), 420.5);
}
END_TEST

Suite * floatconv_suite() {
    Suite *s;
    TCase *tc_bytes_to_double;

    s = suite_create("floatconv");

    tc_bytes_to_double = tcase_create("bytes_to_double");

    tcase_add_test(tc_bytes_to_double, test_bytes_to_double);
    suite_add_tcase(s, tc_bytes_to_double);

    return s;
}


int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = floatconv_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}