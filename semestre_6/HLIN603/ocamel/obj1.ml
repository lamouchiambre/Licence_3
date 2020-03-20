class min (xi : int) =
object (self)
  val mutable x = xi
  method get = x
  method set n = x <- n
  method min y = if self#get < y then self#get else y
end ;;

class min_zero xi =
object
  inherit min xi
  method get = 0
end;;

let o1 = new min 4;;
let o2 = new min_zero 4;;

o1#min 2;;(*self 4*)
o1#min 7;;
o2#min 2;;
o2#min (-2);;
(* on utilise la methode get la plus specifiée, c'est par une liaison dynamique,elle permet l'estension *)

