//
//  Bartlomiej Kunikowski
//
//  Very simple caesar cipher decrypter and crypter program
//
//  Copyright (c) 2020 BartekkPL
//
//  This library is released under the Apache License 2.0.
//  https://github.com/BartekkPL/caesar-cipher/blob/master/LICENSE
//
//  https://github.com/BartekkPL/caesar-cipher
//

#include <iostream>
#include <limits>
#include <string>

void shiftCharacterInRange(int characterShift, char& characterToShift, char rangeBegin, char rangeEnd)
{
  if (characterToShift >= rangeBegin && characterToShift <= rangeEnd)
    {
      if (characterToShift + characterShift <= rangeEnd && characterToShift + characterShift >= rangeBegin)
      {
        characterToShift += characterShift;
      }
      else if (characterToShift + characterShift > rangeEnd)
      {
        int remaindShift = characterToShift + characterShift - rangeEnd - 1;
        characterToShift = rangeBegin + remaindShift;
      }
      else
      {
        int remaindShift = characterToShift + characterShift - rangeBegin + 1;
        characterToShift = rangeEnd + remaindShift;
      }
    }
}

std::string CaesarCipher(const std::string& cipher, int chararcterShift)
{
  std::string result = cipher;
  chararcterShift = chararcterShift % ('z' - 'a');

  auto shiftCharacter = [chararcterShift](char& ch)
  {
    if (ch >= 'a' && ch <= 'z')
    {
      shiftCharacterInRange(chararcterShift, ch, 'a', 'z');
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      shiftCharacterInRange(chararcterShift, ch, 'A', 'Z');
    }
    else
    {
      return;
    }
  };

  for (char& ch : result)
  {
    shiftCharacter(ch);
  }

  return result;
}

int main()
{
  std::cout << "CAESAR CIPHER (DE)CRYPTER" << std::endl << std::endl;
  std::cout << "Enter Caesar cipher you want to (de)crypt: ";

  std::string text;
  std::getline(std::cin, text);
  std::cout << std::endl << std::endl;

  int currentShift = 0;

  char chosenOption = '\0';
  while (chosenOption != 'q' && chosenOption != 'Q')
  {
    std::cout << "Choose an option: " << std::endl;
    std::cout << "- replace characters with \"bigger\" one - key \"d\"" << std::endl;
    std::cout << "- replace characters with \"lower\" one - key \"a\"" << std::endl;
    std::cout << "- exit program - key \"q\"" << std::endl;
    std::cin >> chosenOption;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl << std::endl << std::endl;
    if (chosenOption == 'd' || chosenOption == 'D')
      ++currentShift;
    else if (chosenOption == 'a' || chosenOption == 'A')
      --currentShift;
    else
      continue;
    std::cout << "Original text: " << text << std::endl;
    std::cout << "Modified one (actual shift: " << currentShift << "): " << CaesarCipher(text, currentShift);
    std::cout << std::endl << std::endl << std::endl;
  }
  return 0;
}
