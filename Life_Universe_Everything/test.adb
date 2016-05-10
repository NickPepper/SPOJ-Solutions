with Ada.Integer_Text_Io, Ada.Text_Io;
use Ada.Integer_Text_Io, Ada.Text_Io;
 
procedure Test is
   subtype Small is Integer range 0..99;
   Input : Small;
begin
   loop
      Get(Input);
      if Input = 42 then
         exit;
      else 
         Put (Input);  
         New_Line;
      end if;
   end loop;
end;
