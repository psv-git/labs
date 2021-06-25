<?php
function requireFilesFromPath($path, $allowExtension)
{
    $extensionLen = strlen($allowExtension);
    $fileNamesArray = array_diff(scandir($path), array('.', '..', 'autoload.inc.php'));
    foreach ($fileNamesArray as $fileName) {
        if (is_dir($path . "/" . $fileName)) {
            requireFilesFromPath($path . "/" . $fileName, $allowExtension);
        } else {
            if (strlen($fileName) > $extensionLen) {
                if (substr($fileName , 0 - $extensionLen) == $allowExtension) {
                    require_once($path . "/" . $fileName);
                }
            }
        }
    }
}
