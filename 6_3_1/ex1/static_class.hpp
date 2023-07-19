#pragma once

class static_class{
    public:
      static static_class create();
      ~static_class();
      void hello();
    private:
      static_class() = default;
};