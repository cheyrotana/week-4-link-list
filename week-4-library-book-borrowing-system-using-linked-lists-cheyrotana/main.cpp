#include "utils/LibrarySystem.hpp"

int main() {
    LibrarySystem lib;

    // Implement your logic here

    //test_BookNodeCreation();
    BookNode* book1 = new BookNode("The Great Gatsby", "2024-11-10");
    BookNode* book2 = new BookNode("1984", "2024-11-11");
    BookNode* book3 = new BookNode("To Kill a Mockingbird", "2024-11-10");
    
    lib.addMember("John Doe");
    
    //test_AddAndFindMember();
    Member* johnDoe = lib.findMember("John Doe");
    // Test member borrowing books
    johnDoe->borrowBook("The Great Gatsby", "2024-11-10");
    johnDoe->borrowBook("1984", "2024-11-11");
    //test_FindNonExistentMember();
    Member* janeDoe = lib.findMember("Jane Doe");
    //test_DisplayMemberBooks();
    lib.displayMemberBooks("Jane Doe");
    lib.displayMemberBooks("John Doe");

    // Test member returning books
    johnDoe->returnBook("The Great Gatsby");
    lib.displayMemberBooks("John Doe");

    // Test returning a non-existent book
    johnDoe->returnBook("Non-Existent Book");
    lib.displayMemberBooks("John Doe");
    return 0;
}
