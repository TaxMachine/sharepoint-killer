# Sharepoint Killer
This program probably doesn't matter to you but to me it's somehow important. By an unknown way, Microsoft SharePoint sometimes opens and I couldn't find the source of the problem. So I decided to write a program that kills the process of SharePoint. I know it's not a good solution, but it works for me. I hope it works for you too.

## What is SharePoint?
SharePoint is a web-based collaborative platform that integrates with Microsoft Office. Launched in 2001, SharePoint is primarily sold as a document management and storage system, but the product is highly configurable and usage varies substantially among organizations. Microsoft states that SharePoint has 190 million users across 200,000 customer organizations. It is used by 78% of Fortune 500 companies. SharePoint Online is a cloud-based service that helps organizations share and collaborate with colleagues, partners, and customers. With SharePoint Online, you can access internal sites, documents, and other information from anywhere—at the office, at home, or from a mobile device.

## What does SharePoint do to me?
When the process is running, it takes around 10% of my CPU
![SharePoint](/assets/process.png)
I tried debugging the process, and it seems that it's trying to authenticate to something I don't know what.
![SharePoint](/assets/debug.png)
Has you can see the AuthRetryException is being thrown and the process is trying to authenticate again and again.

## How would it be useful?
I implemented a [vector](/src/processes.hpp) where you can put your own list of blacklisted processes. So you can put known malware's process names and kill them instantly.