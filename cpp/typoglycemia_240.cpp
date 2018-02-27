// Description
//
// Typoglycemia is a relatively new word given to a purported recent discovery about how people read written text. As wikipedia puts it:
// The legend, propagated by email and message boards, purportedly demonstrates that readers can understand the meaning of words in a sentence even when the interior letters of each word are scrambled. As long as all the necessary letters are present, and the first and last letters remain the same, readers appear to have little trouble reading the text.
// Or as Urban Dictionary puts it:
// Typoglycemia
// The mind's ability to decipher a mis-spelled word if the first and last letters of the word are correct.
// The word Typoglycemia describes Teh mdin's atbiliy to dpeihecr a msi-selpeld wrod if the fsirt and lsat lteetrs of the wrod are cerorct.
// Input Description
//
// Any string of words with/without punctuation.
// Output Description
//
// A scrambled form of the same sentence but with the word's first and last letter's positions intact.
// Sample Inputs
//
// According to a research team at Cambridge University, it doesn't matter in what order the letters in a word are,
// the only important thing is that the first and last letter be in the right place.
// The rest can be a total mess and you can still read it without a problem.
// This is because the human mind does not read every letter by itself, but the word as a whole.
// Such a condition is appropriately called Typoglycemia.
// Sample Outputs
//
// Aoccdrnig to a rseearch taem at Cmabrigde Uinervtisy, it deosn't mttaer in waht oredr the ltteers in a wrod are,
// the olny iprmoatnt tihng is taht the frist and lsat ltteer be in the rghit pclae.
// The rset can be a taotl mses and you can sitll raed it wouthit a porbelm.
// Tihs is bcuseae the huamn mnid deos not raed ervey lteter by istlef, but the wrod as a wlohe.
// Scuh a cdonition is arppoiatrely cllaed Typoglycemia.

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <vector>
#include <random>
#include <chrono>

int main()
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  std::string input;
  std::getline(std::cin, input);

  std::istringstream buf(input);
  std::istream_iterator<std::string> beg(buf), end;
  std::vector<std::string> tokens(beg, end);

  for (std::string s : tokens)
    {
      int n = 0;
      if (s.size() > 1)
        {
          std::cout << *s.begin();
          std::string temp = s.substr(1, s.size() - 2);
          std::shuffle(temp.begin(), temp.end(), std::default_random_engine(seed));
          std::cout << temp;
        }
      std::cout << *(s.end() - 1) << " ";
      n = 0;
    }

  return 0;
}
