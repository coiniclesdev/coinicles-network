[CmdletBinding()]
param ()
$web = New-Object System.Net.WebClient
if( -not ( Test-Path $env:APPDATA\.coiniclesnet -PathType Container ) )
{
  coiniclesnet.exe -g
}


$web.DownloadFile("https://site.coinicles.tech/coiniclesnet.signed", "$env:APPDATA\.coiniclesnet\bootstrap.signed")
