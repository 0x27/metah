<?php

echo shell_exec('sh KOD/comp.sh');
echo shell_exec('sh ./program '.$_POST['funkcija'].' '.$_POST['iteracije'].' '.$_POST['ponavljanja'].'  n omega ro_p ro_g m e');

?>