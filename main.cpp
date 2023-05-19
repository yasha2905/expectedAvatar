#include <iostream>
#include <expected>
#include <vector>
#include <algorithm>

struct avatar
{
};
enum class error_code
{
   ok,
   error,
};

using avatar_result = std::expected<avatar, error_code>;

avatar_result add_frame(avatar const& a) { return a; /* std::unexpected<error_code>(error_code::error); */ }
avatar_result add_badge(avatar const& a) { return a; /* std::unexpected<error_code>(error_code::error); */ }
avatar_result add_text(avatar const& a)  { return a; /* std::unexpected<error_code>(error_code::error); */ }

avatar_result make_avatar(avatar const& a, bool const with_frame, bool const with_badge, bool const with_text)
{
   avatar_result result = a;
   if (with_frame)
   {
      result = add_frame(*result);
      if (!result)
         return result;
   }
   if (with_badge)
   {
      result = add_badge(*result);
      if (!result)
         return result;
   }
   if (with_text)
   {
      result = add_text(*result);
      if (!result)
         return result;
   }
   return result;
}


//using namespace std;

int main()
{
    avatar a;
    auto result = make_avatar(a, true, true, false);

    if (result)
    {
       std::cout << "success\n";
    }
    else
    {
       std::cout << "Error: " << (int)result.error() << '\n';
    }
    return 0;
}
