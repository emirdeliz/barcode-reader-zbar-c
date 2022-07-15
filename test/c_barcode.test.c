#include <stdio.h>
#include "../src/c_barcode_utils.h"

int barcode_length = 44;
/**
 * Test 1 for mod 10.
 * @result barcode - 83630000000-4 86170162000-2 00101020217-2 67028153602-9.
 */
char barcode_mod_10_1[] = "83630000000861701620000010102021767028153602";
char barcode_expected_with_check_digits_mod_10_1[] = "836300000004861701620002001010202172670281536029";

/**
 * Test 2 for mod 10.
 * @result barcode - 85630000002-8 98699912310-2 12222102325-4 88525010000-9.
 */
char barcode_mod_10_2[] = "85630000002986999123101222210232588525010000";
char barcode_expected_with_check_digits_mod_10_2[] = "856300000028986999123102122221023254885250100009";

/**
 * Test 1 for mod 11.
 * @result barcode - 23793.38128 60068.823438 40000.063301 3 87570000002000.
 */
char barcode_mod_11_1[] = "23793381286006882343840000063301387570000002000";
char barcode_expected_with_check_digits_mod_11_1[] = "23793381286006882343840000063301387570000002000";

/**
 * Test 2 for mod 11.
 * @result barcode - 23793.38128 60004.220509 69000.050802 7 89810000005105.
 */
char barcode_mod_11_2[] = "23793381286000422050969000050802789810000005105";
char barcode_expected_with_check_digits_mod_11_2[] = "23793381286000422050969000050802789810000005105";

/**
 * This method runs the simple test for the barcode reader.
 * @param char[] barcode - Barcode with 44 digits.
 * @param char[] expected - Barcode expected.
 * @param int mod - The barcode mod (10 or 11).
 * @void - No return value.
 */
void run(char barcode[], char expected[], int mod)
{
	char *result_mod = malloc(48 + 1);
	c_apply_maybe_check_digit_to_barcode(barcode, result_mod, barcode_length);

	if (strcmp(result_mod, expected) != 0)
	{
		printf("FAILED: %s\n", result_mod);
	} else {
		printf("PASSED: %s\n", result_mod);
	}
};

int main()
{
	run(barcode_mod_10_1, barcode_expected_with_check_digits_mod_10_1, 10);
	run(barcode_mod_10_2, barcode_expected_with_check_digits_mod_10_2, 10);
	run(barcode_mod_11_1, barcode_expected_with_check_digits_mod_11_1, 11);
	run(barcode_mod_11_2, barcode_expected_with_check_digits_mod_11_2, 11);
	return 0;
}
