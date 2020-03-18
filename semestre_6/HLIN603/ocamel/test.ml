let test = function l -> l*2;;

(*let rec reverse = function
  | [] -> []
  | e :: tl -> (reverse tl) @ [e];;
 *)

let rec occurance l o =
  match l with
  |[] -> 0
  |e::tl -> if e=o then 1 + (occurance tl o)
                   else (occurance tl o);;
                         
let rec trier l =
  match l with
  |[] -> true
  |[e] -> true
  |e :: b :: tl -> (e <= b) && (trier (b :: tl));;
  

let rec insert o = function
  |[] -> [o]
  |a :: b :: tl -> if ((a <= o) && (o <= b))  then (a :: o :: b :: tl)
                   else a :: (insert o  (b::tl));;
let rec insert2 o = function
  |[] -> [o]
  |a :: tl -> if (a <= o) then (a :: o :: tl)
              else a :: (insert2 o tl);;
  

let rec trierL = function
  |[] -> []
  |[x] -> [x]
  |e :: tl -> trierL(insert2 e tl);; 

(*** Execice 2 ***)

(*Q1*)

type form =
  |Top|Bot
  |Var of string
  |Not of form
  |And of form * form
  |Or of form * form
  |Imp of form * form
  |Equ of form * form;;


(*Q2*)

let rec aff_log = function
  |Top -> "true"
  |Bot -> "false"
  |Var e -> e;
  |Not e -> "~" ^ aff_log(e)
  |And (a, b) -> "(" ^ (aff_log a) ^ " and " ^ (aff_log b) ^ ")" 
  |Or (a, b) -> "(" ^ (aff_log a) ^ " or " ^ (aff_log b) ^ ")"
  |Imp (a, b) -> "(" ^ (aff_log a) ^ " => " ^ (aff_log b) ^ ")"
  |Equ (a, b) -> "(" ^ (aff_log a) ^ " <=> " ^ (aff_log b) ^ ")";;

let rec simple_T_And = function
  |(f1, Top)|(Top, f1) -> f1
  |(e, Bot)|(Bot, e) -> Bot
  |(r1, r2) -> And (r1, r2);;

let rec simple_T_Or = function
  |(f1, Top)|(Top, f1) -> Top
  |(e, Bot)|(Bot, e) -> e
  |(r1, r2) -> Or (r1, r2);;

let rec simple_T_Imp = function
  |(f1, Top) -> Top
  |(Top, f2) -> f2
  |(e, Bot) -> Not(e)
  |(Bot, r) -> Top
  |(r1, r2) -> Imp (r1, r2);;


let sum l = List.fold_left (fun acc e -> acc + e) 0 l;;

let rec sum_aux acc = function
  | [] -> acc
  | e :: tl -> sum (acc + e) tl;;



type number =
| Int of int
| Float of float;;

