#pragma once
#include <vector>
enum class status {
  Success,
  Failure,
  Nice_try,
  Almost,
};
static std::vector<status> every_status{status::Success, status::Failure,
                                        status::Nice_try, status::Almost};
status random_status();
