#include <iostream>
#include <iomanip>
#include <string>
#include <string_view>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

enum SUBJECT {
  CS = 1, BCA, CIT,
};
std::map<SUBJECT const, std::string const>  const Subject{
  { CS,   "Computer Science"s },
  { BCA,  "Business Computer Applications"s },
  { CIT,  "Computer Information Technology"s },
};

enum RUBRIC {
  COSC = 1, BCIS, ITSC, ITSE,
};
std::map<RUBRIC const, std::string const> Rubric {
  { COSC, "COSC"s },
  { BCIS, "BCIS"s },
  { ITSC, "ITSC"s },
  { ITSE, "ITSE"s },
};

std::map<size_t const, size_t const> Course {
  { 1, 1436 },
  { 2, 1437 },
  { 3, 2436 },
  { 4, 1301 },
  { 5, 1405 },
};

std::map<size_t const, size_t const> Section {
  { 1, 82001 },
  { 2, 82002 },
  { 3, 82003 },
  { 4, 82701 },
  { 5, 82702 },
};

/*
 *  MARK:  main()
 */
int main(int argc, char const * argv[]) {

  for (auto s_ : Subject) {
    std::cout << std::setw(3) << s_.first
              << ": "s
              << s_.second
              << '\n';
  }
  std::cout << std::endl;

  for (auto r_ : Rubric) {
    std::cout << std::setw(3) << r_.first
              << ": "s
              << r_.second
              << '\n';
  }
  std::cout << std::endl;

  for (auto c_ : Course) {
    std::cout << std::setw(3) << c_.first
              << ": "s
              << std::setw(5) << c_.second
              << '\n';    
  }
  std::cout << std::endl;

  for (auto s_ : Section) {
    std::cout << std::setw(3) << s_.first
              << ": "s
              << std::setw(5) << s_.second
              << '\n';
  }
  std::cout << std::endl;

  /* default - std::initializer_list */
  auto const lst = {
    "Init"s, "Ialize"s, "R_list"s,
  };
  std::cout << "lst: "s;
  std::for_each(lst.begin(), lst.end(),
    [](auto const & l_) {
      std::cout << l_;
    });
  std::cout << std::endl;

  auto const vec = std::vector<std::string> {
    /* observe - mixed 'std::string' and 'char *' */
    "Ve"s, "Ct", "Or"s,
  };
  std::cout << "vec: "s;
  std::copy(vec.cbegin(), vec.cend(),
    std::ostream_iterator<std::string>(std::cout << ""s));
  std::cout << std::endl;

  auto const dll = std::list<std::string_view> {
    /* observe - mixed 'std::string_view', 'std::string', and 'char *' */
    "Stri"sv, "Ng_v", "Iew"s,
  };
  std::cout << "dll: "s;
  for (auto const d_ : dll) {
    std::cout << d_;
  }
  std::cout << std::endl;

  std::cout << std::endl;

  return 0;
}
