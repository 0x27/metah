<?php


if ((is_numeric($_POST['iteracije']) == false) || (is_numeric($_POST['ponavljanja']) == false) || (is_numeric($_POST['n']) == false) 
    || (is_numeric($_POST['omega']) == false) || (is_numeric($_POST['ro_p']) == false) || (is_numeric($_POST['ro_g']) == false) 
   || (is_numeric($_POST['m']) == false) || (is_numeric($_POST['e']) == false))
    header('Location: index.php?ob=1');
else 
    {
    $cmd = 'cd KOD ; ./program ' . $_POST['funkcija'] . ' ' . $_POST['iteracije'] . ' ' . $_POST['ponavljanja'] . ' ' . $_POST['n'] . ' ' . $_POST['omega'] . ' ' . $_POST['ro_p'] . ' ' . $_POST['ro_g'] . ' ' . $_POST['m'] . '   ' . $_POST['e']; 
    exec($cmd);
    header('Location: index.php');
    }
?>
