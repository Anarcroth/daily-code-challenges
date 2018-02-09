#!/bin/python

bookshelf_size = raw_input("Enter shelf sizes: ");
bookshelf_size = bookshelf_size.split();

total_book_size = 0;
for sz in bookshelf_size:
    total_book_size += int(sz);

current_books = raw_input("Enter size of books: ");
current_books = current_books.split();
