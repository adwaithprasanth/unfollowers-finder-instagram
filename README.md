# Unfollowers Finder Instagram (UFI)

**UFI** is a simple C-based utility that helps you identify **Instagram accounts you follow who do not follow you back**.

It works by comparing two text files:

* Your **followers list**
* Your **following list**

and outputs usernames that exist in *following* but not in *followers*.

---

## 📌 What this project does

* Reads two text files containing Instagram usernames
* Compares them line by line
* Prints usernames present in **following** but missing from **followers**

In simple terms:

> **Who am I following that isn’t following me back?**

---

## 📂 Project Structure

```
unfollowers-finder-instagram/
├── compare.c        # C source code
├── list1.txt        # Followers list
├── list2.txt        # Following list
└── README.md
```

---

## 📥 Step 1: Export Instagram Data

Follow these steps carefully on Instagram:

1. Go to **Account Center**
2. Navigate to **Your information and permissions**
3. Click **Download your information**
4. Select **Create export**
5. Choose **Export to device**
6. Set **Date range** to **All time**
7. Click **Customize information**
8. Under **Connections**, check **only**:

   * Followers
   * Following
9. Uncheck **all other options**
10. Click **Save**, then **Start export**

Instagram will prepare your data. This may take some time.

---

## 📦 Step 2: Extract Required Files

1. Download the export once it’s ready (ZIP file)
2. Extract the ZIP file
3. Navigate to:

```
connections/
```

4. Locate and extract:

   * `followers_1.json`
   * `following.json`

---

## 🧹 Step 3: Clean the Data

Instagram exports contain extra metadata (links, timestamps, IDs).

You must convert both files into **plain text lists**:

* One username per line
* No URLs
* No dates or timestamps

💡 You can use **any AI tool or text editor** to clean the data.

> ⚠️ Automated cleaning will be added in a future version.

After cleaning:

* Save followers as `list1.txt`
* Save following as `list2.txt`

---

## ⚙️ Step 4: Run DiffGram

### Clone the repository

```bash
git clone <repo-url>
cd unfollowers-finder-instagram
```

### Copy your files

Place `list1.txt` and `list2.txt` into the project directory.

### Compile and run

```bash
gcc compare.c 
./a.out 
```
```bash
gcc compare.c 
a.exe 
```

---

## ✅ Output

The program prints:

```
Names present in Following but NOT in Followers:

username_1
username_2
username_3
```

Each line represents an account that does **not** follow you back.

---

## 🛠 Assumptions & Notes

* One username per line
* Case-sensitive comparison
* No duplicate usernames
* Files must be plain text (`.txt`)

---

If you found this project helpful or interesting, please ⭐ the repository. Your support keeps the midnight ideas alive! 🌙
