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
    class Mastermind
    {
        private $code;
        public $essai;
        public $nb_coup;
        public $nb_bienP;
        public $nb_malP;


        public function genereCode(){
            $chiffre = array(rand(0,9), rand(0,9), rand(0,9), rand(0,9));
            // for($i = 0; $i < 4; $i++){
            //     $chiffre[] = rand(0,9);
            //     //echo rand(0,9);
            //     echo $chiffre[i];
            // }

            $code = $chiffre;
            //echo $code[0];
        }
        public function getEssai($tab){
            $tmp = str_split($tab);
            for ($i=0; $i < 4; $i++) { 
                $essai[$i] = intval($tmp[$i]);
                //echo $essai[$i];
            }
        }  
        
        public function bienPlacer($tab){
            $tmp = $code;
            $nb = 0;
            for ($i=0; $i < 4; $i++) { 
                if ($tab[i] == $code[$i]) {
                    $nb = $nb +1;
                    $tab[i]=-1;
                    $code[i]=-1;
                }
            }
            //echo $nb;
        } 
        public function test($tab){
            $tmp1;
            $tmp1 = $this->getNbCoup();
            $this->getEssai($tab);
            //$essai = 1;
            $tmpEssai = $this->essai; 
            echo $this->nb_coup;
            echo $tmp1;
            //$tmpCode = $this->$code;
            $this->bienPlacer($tmpEssai);
        }
        public function getNbCoup(){
            $this->nb_coup = 1;
            return $this->nb_coup;
        }
        
        public function augNb_coup(){
            $nb_coup = rand(0,9);
        } 
    }

    $m1 = new Mastermind;
    $m1->genereCode();
    //echo $m1->getNbCoup();
    //echo $m1->getNbCoup();
    $tab = "1234";
    $m1->test($tab);
    
    ?>
</body>
</html>