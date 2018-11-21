#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct S {
   string words;
   string operator()() { return words; }
   S operator()(string word) { return {words + (words==""?"":" ") + word}; }
 } say;

 //solution presented to you during office hours did not meet all tests, had to modify.


int main() {
    assert(say() == "");
    assert(say("Bepis")() == "Bepis");
	  assert(say("Bepis")("Pls")() == "Bepis Pls");
}
