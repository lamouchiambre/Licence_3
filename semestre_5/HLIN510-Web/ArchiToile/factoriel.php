<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
<?php
    function factoriel($x){
        if($x == 0){
            return 1;
        }else {
            return $x*factoriel($x -1);
        }
    } 
?>
<h1>Factorielle</h1>
<form method=get>
<label for='x'>X</label>
<input type="number" name='x' id='x'>
<input type="submit" value="Factoriel" name ="fact">
<?php 
    if (isset($_GET['x'])) {
        echo "factoriel(" .$_GET['x'] .")= " .factoriel($_GET['x']);    
    }
?> 
</form>
</body>
</html>

