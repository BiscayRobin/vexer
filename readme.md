# VEXER

Vexer is a library that implement C++ like vectors.

## functions format

- C++: `v.XXX(args)`
- C: `vector_XXX(vector* v, args)`

## Already implemented
 - [X] new :
	  ```C
	vector *c;
	c = vector_new();
	```
 - [X] delete
  	```C
	vector *c = vector_new();
	vector_delete(c); // don't forget de delete inside's data
	```
 - [X] push
	  ```C
	vector *c = vector_new();

	vector_push(c, 36); // Push raw data that is known to be smaller than a (void*)
	
	char* string = malloc(strlen("Bonjour!") + 1);
	strcpy(string,"Bonjour!");
	vector_push(c, string); // push adress of data to be stored

	char* string_local = "Buenos Dias!";
	vector_push(c,string_local); // be carefull with local scoped adresses
	```
 - [X] pop
	  ```C
	vector *c = vector_new();
	vector_push(c, "Kumusta!");
	
	void * res = vector_pop(c); // up to you to make good type conversion if needed
	```
 - [X] front
	  ```C
	vector *c = vector_new();
	vector_push(c, "Namaste!");

	void * res = vector_front(c); // up to you to make good type conversion if needed
	```
 - [X] back
    ```C
	vector *c = vector_new();
	vector_push(c, "Zdravstvuyte!");

	void * res = vector_back(c); // up to you to make good type conversion if needed
	```
 - [X] at
    ```C
   vector *c = vector_new();
	vector_push(c, "Hei!");
   
	void * res = vector_at(c,0); // up to you to make good type conversion if needed
	```
 - [X] empty
	  ```C
	vector *c = vector_new();
	
	if(vector_empty(c) == true) {
		printf("Hallo!");
	} else {
		printf("Hello!");
	}
	```
 - [X] size
	  ```C
	vector *c = vector_new();
	
	size_t res = vector_size(c);
	```
 - [X] capacity
 	  ```C
	vector *c = vector_new();
	
	size_t res = vector_capacity(c);
	```
 - [X] maxSize
    ```C
	size_t res = vector_maxSize();
	```
 - [X] insert
    ```C
	vector *c = vector_new();

	vector_insert(c, 0, "Buongiorno!");
	``` 
 - [X] clear
	  ```C
	vector *c = vector_new();
	
	vector_clear(c);
	```
 - [X] shrinkToFit
	  ```C
	vector *c = vector_new();
	vector_push(c, "Yeoboseyo!");

	vector_shrinkToFit(c);
	```
 - [X] reserve
	  ```C
	vector *c = vector_new();
	
	vector_reserve(c, 20);
	```
 - [X] resize
	  ```C
	vector *c = vector_new();

	vector_resize(c, 30); // same as reserve();

	vector_resize(c, 15); // be carefull all data above this point will be lost
	```
 - [X] data
	  ```C
	vector *c = vector_new();

	void ** res = vector_data(c);
	```
 - [ ] erase
 - [X] swap
	  ```C
	vector *c = vector_new();
	vector *d = vector_new();

	vector_swap(c,d);
	```

## Future features
 - [ ] Allocators
 - [ ] qsort