#ifndef C_FILE_READ_HPP
#define C_FILE_READ_HPP
#include <cstdio>
#include <cstdlib>
#include <memory>
#include <string>
class CFileRead{
    public:
      CFileRead();
      ~CFileRead();
      void print_next_line();
      void print_size()const;
    private:
      FILE* file_handle = nullptr;
};
#endif
