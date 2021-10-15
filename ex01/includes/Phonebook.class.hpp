#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include <iostream> 
#include <iomanip>
#include <string.h>
#include "./Contact.class.hpp"

class Phonebook {
  public:
    Contact contacts[8];

    Phonebook(void);
    ~Phonebook(void);

    void addContact(void);
    void searchContacts(void);

  private:
    static int _counter;

    void _printTableHeader(void);
    void _printTable(void);
    void _printStr(std::string str);
    void _printRepeatedChar(char c, int len);
};

#endif