
#include "Enigma.h"
#include "Rotor.h"
#include "Plugboard.h"
#include "Reflector.h"
#include "helper.h"
#include "errors.h"

#include "catch.hpp"

TEST_CASE("testing here ", "[is_number_range_correct]"){
  REQUIRE(is_number_range_correct(1) == true);
  REQUIRE(is_number_range_correct(0) == true);
  REQUIRE(is_number_range_correct(25) == true);
  REQUIRE(is_number_range_correct(26) == false);
}

TEST_CASE("SSS", "[is_duplicate_int]"){
  // REQUIRE(is_duplicate_int([]) == true);
  // REQUIRE(is_duplicate_int([]) == true);
  // REQUIRE(is_duplicate_int([]5) == true);
  // REQUIRE(is_duplicate_int([]6) == false);
}
