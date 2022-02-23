#include <check.h>
#include <stdlib.h>

#include "../src/intconv.h"

START_TEST(test_bytes_to_int)
{
    uint8_t i[8] = {
        44,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
    };

    uint64_t res = BYTES_TO_INT(i);
    ck_assert_uint_eq(res, 300);
}
END_TEST

Suite * intconv_suite() {
    Suite *s;
    TCase *tc_bytes_to_int;

    s = suite_create("intconv");

    tc_bytes_to_int = tcase_create("bytes_to_int");

    tcase_add_test(tc_bytes_to_int, test_bytes_to_int);
    suite_add_tcase(s, tc_bytes_to_int);

    return s;
}


int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = intconv_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}