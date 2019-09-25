<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Champs</title>
</head>
<body>
    <?php
        $larticle=array('marteau'=>10, 'tenaille'=>5, 'vis=>'=>5.2, 'clou'=>5.8, 'tournevis'=>7, 'ciseau'=>4, 'toile émeri'=>3);

    ?>
    <form methode=get>
    <label for='marteau'> Nb marteau </label>
    <input type="number" name='marteau' id = 'marteau'><br>
    <label for='tenaille'> Nb tenaille </label>
    <input type="number" name='tenaille' id = 'tenaille'><br>
    <label for='marteau'> Nb vis </label>
    <input type="number" name='vis' id = 'vis'><br>
    <label for="number"> Nb clou </label>
    <input type="number" name='clou' id = 'clou'><br>
    <label for="number"> Nb tournevis </label>
    <input type="number" name='tournevis' id = 'tournevis'>
    <input type ="submit" value="envoyer">
    <?php
        $panier = array();
        function remplirPanier(){
            echo "sa marche si " .$_GET["marteau"];
            $panier["marteau"]=$_GET["marteau"];
            $panier["tenaille"]=$_GET["tenaille"];
            $panier["vis"]=$_GET["vis"];
            $panier["clou"]=$_GET["clou"];
            $panier["tournevis"]=$_GET["tournevis"];
            var_dump($panier);
        }
        if($panier != []){
            remplirPanier();
        }
    
    ?>
</body>
</html>