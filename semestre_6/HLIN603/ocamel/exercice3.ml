class cte (n : int) =
object
  val valeur = n
  method eval = valeur
end;;

class inv (n : inv) =
object
  
  method eval = 0 - n#eval
              method print = print_string
end;;

class exp =
object
  method eval = 0
  method print = print_string " "
end;;

class add (l : add) (r: add) =
object
  val left = l
  val right = r
  method eval = l#eval + r#eval
  method print = print_string "(";
                 left#print;
                 print_string "+";
                 right#print;
                 print_string ")";
end;;

