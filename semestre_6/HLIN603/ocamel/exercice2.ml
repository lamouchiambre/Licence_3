class account b =
object (self)
  val mutable balance = 0.0
  method get = balance
  method deposit a = balance <- balance +. a
  method withdraw a = balance <- balance -. a
  method print = print_float balance; print_newline()
  initializer self#deposit b
end;;

class interest_account b =
object
inherit account b
method interset  =
  balance <- balance +. 5. *. balance /. 100.
end;;                                                 

(*les expression reguliere query_replace_regexp \(.\) -> \1 *)

class bank =
object
  val mutable comptes_list = []
  method add (a : account) =
    comptes_list <- a::comptes_list
  method balance =
    List.fold_left (fun a b -> a +.b#get) 0. comptes_list
  method print =
    List.iter (fun a -> a#print) comptes_list
  method fees =
    List.iter (fun a -> a#withdraw (a#get *. 5. /. 100.)) comptes_list
  method deposite x =
    List.iter (fun a -> a#deposit x) comptes_list
  end;;

class ['a] bank =
object
  inherit 
