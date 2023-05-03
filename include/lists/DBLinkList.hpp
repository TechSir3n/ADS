#ifndef ADS_INCLUDE_LISTS_DBLINKLIST_HPP_
#define ADS_INCLUDE_LISTS_DBLINKLIST_HPP_

namespace ADS {
template <typename Type> class DBLinkList {
  private:
    using Node = DBLinkList<Type> public : DBLinkList() {}

    virtual ~DBLinkList() noexcept {}

  private:
    Node* head;
    unsigned int length;
};

} // namespace ADS

#endif