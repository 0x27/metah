<?php

$cmd = 'cd KOD ; ./program ' . $_POST['funkcija'] . ' ' . $_POST['iteracije'] . ' ' . $_POST['ponavljanja'] . ' ' . $_POST['n'] . ' ' . $_POST['omega'] . ' ' . $_POST['ro_p'] . ' ' . $_POST['ro_g'] . ' ' . $_POST['m'] . '   ' . $_POST['e']; 
exec($cmd);
header('Location: index.php');
?>
