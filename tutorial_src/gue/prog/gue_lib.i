/* gue_lib.i */
 %module gue_lib
 %{
 /* Put header files here or function declarations like below */
 extern int init();
 extern bool isGreater(int x);
 extern void answer(int x);
 %}
 
 extern int init();
 extern bool isGreater(int x);
 extern void answer(int x);
